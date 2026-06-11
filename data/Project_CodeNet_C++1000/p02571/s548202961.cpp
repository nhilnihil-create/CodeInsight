#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define lop(i,a,b) for(ll i=a;i<b;i++)
using namespace std;

void func(){
    string s,t;
    cin>>s>>t;
    int ss=s.size(),ts=t.size(),score,min=ts;
    lop(i,0,ss-ts+1){
        score=0;
        lop(j,0,ts){
            if(s[i+j]!=t[j])
                score++;
        }
        if(score<min)min=score;
        if(!min)break;
    }
    cout<<min<<endl;
}

int main(){
    fastio;
    func();
}