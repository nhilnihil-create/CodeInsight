#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    string s;
    cin >> s;
    int n=s.size();
    int ans=0;
    reverse(s.begin(),s.end());
    s=s+"0";
    int c=0;
    rp(i,n+1){
        int d=s.at(i)-'0';
        if(c==1) d++;
        if(d==10){
            c=1;
            continue;
        }
        if(d<=4) {
            ans += d;
            c=0;
            continue;
        }
        if(d>=6){
            ans += 10-d;
            c=1;
            continue;
        }
        if(d==5){
            ans+=5;
            if(s.at(i+1)-'0'>=5){
                c=1;
            }
            else{
                c=0;
            }
        }
    }
    cout << ans << endl;
    return 0;

}