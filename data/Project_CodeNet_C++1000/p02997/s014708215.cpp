#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, k;
    cin>>n>>k;
    set<pair<int, int> > st;
    for(int i = 1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            st.insert(make_pair(i, j));
        }
    }

    if(k > (n-2)*(n-1)/2) {
        cout<<-1<<endl;
        return 0;
    }
    queue<pair<int, int> > que;
    for(int i = 1;i<=n-2;i++){
        for(int j = i+1;j<=n-1;j++){
            que.push(make_pair(i, j));
        }
    }
    rep(i, k){
        auto p = que.front();que.pop();
        st.erase(p);
    }
    cout<<st.size()<<endl;
    for(auto p : st) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}