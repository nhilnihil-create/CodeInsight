/**
*    created: 17.05.2020 12:32:42
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;
//ダブリング？
//漸化式的な感じか,dp?むずそう
//RL隣り合っているところ見つけていって逆算か
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a;
    //a[i]=j:(s[j],s[j+1])=(L,R),(R,L)
    //i%2==1:(L,R),else:(R,L)
    rep(i,n){
        if(i==n-1){
            break;
        }
        if(s[i]!=s[i+1])
            a.push_back(i);
    }
    //rep(i,n)cout << s[i] ;
    //cout  << endl;
    //rep(i,a.size())cout <<"a:"<< a[i] << endl;
    //s[k]の子が何番目のL,Rloopに入るか
    int j = 0;
    vector<int> ans(n,0);
    rep(i,n){
        //cout << a[j] << endl;
        if(s[i]=='R'){
            //to a[j]loop
            int x = a[j] - i; //times of step to loop
            if(x%2)
                ans[a[j] + 1]++; //s[i]の子はL
            else
                ans[a[j]]++;
        }
        if(s[i]=='L'){
            //to a[j-1]loop
            int x = i - a[j - 1]; //times of step to loop
            if(x%2)
                ans[a[j-1] + 1]++; //s[i]の子はL
            else
                ans[a[j-1]]++;
        }
        if(i>=a[j]){
            if(j==a.size()){
                continue;
            }
            j++;
        }
    }
    rep(i, n){
        cout << ans[i];
        if(i!=n-1)cout<< " ";
        if(i==n-1)cout << endl;
    }
}