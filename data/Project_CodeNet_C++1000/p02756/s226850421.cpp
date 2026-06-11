#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin>>s;
    int q; cin>>q;
    int rev=0;
    string r="", l="";
    for (int i=0; i<q; i++){
        int t; cin>>t;
        if(t==1) rev++;
        else if(t==2){
            int f; cin>>f; char c; cin>>c;
            if((f+rev)%2==1) l=l+c;
            else if((f+rev)%2==0) r=r+c;
        }
    }
    if(rev%2==1){
        s = s+r;
        reverse(s.begin(), s.end());
        s = s+l;
    }
    else{
        reverse(l.begin(), l.end());
        s = l + s + r;
    }
    cout << s << endl;
}