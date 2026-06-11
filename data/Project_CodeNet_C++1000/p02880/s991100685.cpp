#include<bits/stdc++.h>
using namespace std;

long long n,m,a=1,c;
string s;
bool b;

int main(){
    cin>>n;
    vector<int>v(100,0);
    for (int i=1; i<10; i++){
        for (int j=1; j<10; j++){
            v[i*j]++;
        }
    }
    if (v[n]>0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

}
