#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int main(){
    AC
    int k;
    string s;
    cin>>k>>s;
    if(s.size()<=k)
        cout<<s<<endl;
    else{
        for(int i=0; i<k; i++)
            cout<<s[i];
        cout<<"..."<<endl;
    }
        

}