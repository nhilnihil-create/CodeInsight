#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
    int a[n];
    for(int i = 0;i<n;++i){
        cin>>a[i];
        if(i!=0){
            if(a[i]>a[i-1])--a[i];
            if(a[i]<a[i-1]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
	return 0;
}