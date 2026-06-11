#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<queue<int>>A(N);
    queue<int>next;
    map<int,int>Mp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-1; j++) {
            int a;
            cin >> a;
            a--;
            A[i].push(a);
        }
        Mp[i] = A[i].front();
        next.push(i);
    }
    int sum = 0;
    int i = 0;
    while(true) {
        i++;
        set<int>st;
        while(!next.empty()) {
            int x = next.front();
            next.pop();
            if(Mp[Mp[x]] == x) {
                st.insert(x);
                st.insert(Mp[x]);
            }
        }
        for(int x:st) {
            A[x].pop();
            if(!A[x].empty()) {
                Mp[x] = A[x].front();
                next.push(x);
            }
            sum++;
        }
        st.clear();
        if(sum == N*(N-1)) {
            break;
        }
        if(next.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << i << endl;
}