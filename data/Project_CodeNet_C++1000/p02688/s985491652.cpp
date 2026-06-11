#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,d,a,count[101],sum=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        count[i]=0;
    }
    for(int i=0;i<k;i++){
        cin >> d;
        for(int j=0;j<d;j++){
            cin >> a;
            count[a-1]++;
        }
    }
    for(int i=0;i<n;i++){
        if(count[i]==0) sum++;
    }
    cout << sum;
}