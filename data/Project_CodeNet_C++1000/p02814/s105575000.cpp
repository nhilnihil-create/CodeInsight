#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <bits/stdc++.h> 
 
using namespace std;
 
long long f(long int x,long int y){
    if (x<y) swap(x,y);
    if (y==0) return x;
    x=x%y;
    return f(x,y);
}
 
int main(){
    long int N,M;
    cin>>N>>M;
    long int a[N];
    cin>>a[0];
    int n=0;
    while(a[0]%2==0){
        a[0]=a[0]/2;
        n++;
    }
    for (int i=1;i<N;i++){
        cin>>a[i];
        for (int j=0;j<n;j++){
            if (a[i]%2==0) a[i]=a[i]/2;
            else{
                cout<<0<<endl;
                return 0;    
            }
        }
        if (a[i]%2==0){
        	cout<<0<<endl;
            return 0;    
        }
    }
    M=M/pow(2,n-1);
    long long x=a[0];
    for (int i=1;i<N;i++){
        x=x*(a[i]/f(x,a[i]));
        if (x>M){
            cout<<0<<endl;
            return 0;
        }
    }
    M=M/x;
    cout<<(M+1)/2<<endl;
 
    return 0;
}