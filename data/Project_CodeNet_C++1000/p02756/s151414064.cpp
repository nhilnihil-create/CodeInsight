#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

    string s;
    ll q;
    cin >> s >> q;
    ll sign=1;
    vector<char> v1,v2;
    for(ll i=0;i<q;i++){
        ll t;
        cin >>t;
        if(t==1)sign*=-1;
        else{
            ll f;
            char c;
            cin >> f >> c;
            if(sign==1){
                if(f==1){
                    v1.push_back(c);
                }
                else{
                    v2.push_back(c);
                }
            }
            else{
                if(f==1){
                    v2.push_back(c);
                }
                else{
                    v1.push_back(c);
                }
            }
        }
    }

    

    if(sign==1){
        for(ll i=v1.size()-1;i>=0;i--)cout << v1[i];
        for(ll i=0;i<s.size();i++)cout << s[i];
        for(ll i=0;i<v2.size();i++)cout << v2[i];
        cout << endl;
    }
    else{
        for(ll i=v2.size()-1;i>=0;i--)cout << v2[i];
        for(ll i=s.size()-1;i>=0;i--)cout << s[i];
        for(ll i=0;i<v1.size();i++)cout << v1[i];
        cout << endl;
    }

}