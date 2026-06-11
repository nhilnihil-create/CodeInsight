#include<bits/stdc++.h>
using namespace std;

long long n,m,a,c;
bool b;

int main(){
    cin>>n;
    vector<int>v(n,0);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            a+=v[i]*v[j];
        }
    }
    cout<<a<<endl;
}
