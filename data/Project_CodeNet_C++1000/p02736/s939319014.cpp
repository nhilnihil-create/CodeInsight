#include<bits/stdc++.h>
using namespace std;
long long cnt = 0;
void div2_up(int x){
    if ((x > 0) && ((x & 1) == 0)){
        cnt++;
        div2_up(x / 2);
    }
}
void div2_down(int x){
    if (x > 0 && ((x & 1) == 0)){
        cnt--;
        div2_down(x / 2);
    }
}
int main(){
    int N; cin >> N;
    string s; cin >> s;
    vector<int> A;
    vector<bool> v;
    bool flag = false;

    for (int i = 0; i < N; i++){
        A.push_back(s[i] - '0' - 1);
        if (A[i] == 1)flag = true;
    }
    
    for (int i = 1; i <= N; i++){
        v.push_back(cnt == 0);
        div2_up(N - i);
        div2_down(i);
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += (v[i] && A[i] % 2 == 1);
    }
    if ((sum % 2) == 1) {
        cout << 1 << endl;
    }
    else if (flag){
        cout << 0 << endl;
    }
    else{
        for (int i = 0; i < N; i++)
        {
            A[i] /= 2;
        }
        int sum2 = 0;
        for (int i = 0; i < N; i++)
        {
            sum2 += (v[i] && A[i] % 2 == 1);
        }
        if (sum2 % 2 == 1){
            cout << 2 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        
    }
}