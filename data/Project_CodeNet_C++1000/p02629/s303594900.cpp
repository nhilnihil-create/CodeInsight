#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    long long int n,k=0;
    string s="abcdefghijklmnopqrstuvwxyz";
    cin>>n;
    vector<int>b(10000);
    for(long long int i=0;n>0;i++){
        n=n-1;
        b[i]=n%26;
        k=i;
        n=n/26;
    }
    for(long long int i=k;i>=0;i--){
        cout<<s[b[i]]<<flush;
    }
    cout<<endl;
}
