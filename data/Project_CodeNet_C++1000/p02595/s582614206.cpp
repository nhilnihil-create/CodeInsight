#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    vector<double>a(n);
    vector<double>b(n);
    int m=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if(sqrt(pow(a[i],2)+pow(b[i],2))<=d)m++;
    }
    cout<<m<<endl;
    return 0;
}