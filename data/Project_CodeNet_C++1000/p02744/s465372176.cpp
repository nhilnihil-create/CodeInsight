#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    cs
    int n;
    cin>>n;
    queue<string> q;
    q.push("a");
    while(!q.empty()) {
        string t=q.front();int l=t.size();
        if(l==n) break;
        q.pop();char z='a';
        rep(i,l) z=max(z,t[i]);
        for(char c='a';c<=z+1;c++) q.push(t+c);
    }
    while(!q.empty()) {
        cout<<q.front()<<'\n';
        q.pop();
    }
}