#include<iostream>
using namespace std;

int main()
{
    int n,count=0;
    cin >> n;
    long a[n];
    for(long i=0;i<n;i++){
        cin >> a[i];
    }

    for(long i=0;i<n-2;i++){
        for(long j=i+1;j<n-1;j++){
            if(a[i]==a[j])    continue;
            for(long k=j+1;k<n;k++){
                if(a[i]==a[k] || a[j]==a[k])    continue;
                if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[k]+a[j]>a[i]) count++;
            }
        }
    }

    cout << count <<"\n";

    return 0;
}