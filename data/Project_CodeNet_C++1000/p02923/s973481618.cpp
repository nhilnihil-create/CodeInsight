#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int c[n],b[n];
    c[0]=0;
    cin>>b[0];
    for(int i=1;i<n;i++){
        cin>>b[i];
        if(b[i]>b[i-1]){
            c[i]=0;
        }
        else{
            c[i]=c[i-1]+1;
        }
    }
    sort(c,c+n);
    cout<<c[n-1];
	return 0;
}
