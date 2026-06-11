#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;
    queue<string> que;
    que.push("a");
    while(true){
        string s = que.front();
        if(s.size() == n)break;
        que.pop();
        char i = 'a';
        char r ='a'; rep(j,s.size())r = max(r,s[j]);
        while (r >= i - 1) {
            que.push(s + i);
            i++;
        }
    }
    while(!que.empty()){
        cout << que.front() << endl;
        que.pop();
    }

}
