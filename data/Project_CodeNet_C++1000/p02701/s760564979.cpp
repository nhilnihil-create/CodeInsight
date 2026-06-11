#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007
#define PI 3.1415


int main(){
    int n;
    cin>>n;
    
    set<string> a;
    string d;
    for(int i=0;i<n;i++){
        cin>>d;
        a.insert(d);
    }
    
    cout<<a.size()<<endl;
}

