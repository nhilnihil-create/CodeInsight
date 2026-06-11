#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
     cin>>n;
    while(1){
        int k=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            k++;
        }
    }
    if(k!=0){
        n++;
    }
    else{
        break;
    }

}
cout<<n;
	return 0;
}
