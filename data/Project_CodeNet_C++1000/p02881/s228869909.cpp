#include<bits/stdc++.h>
using namespace std;

long long n,m,a=1,c;
string s;
bool b;

int main(){
    cin>>n;
    vector<int>v;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i==0){
            v.push_back(i);
        }
    }
    cout<<v[v.size()-1]+(n/v[v.size()-1])-2<<endl;
}
