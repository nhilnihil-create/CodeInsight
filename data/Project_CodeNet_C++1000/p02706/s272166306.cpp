#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int ass=0,t;
    while(m--){
    	cin>>t;
    	ass+=t;
    }if(ass>n){
    	cout<<-1;
    }else cout<<n-ass;
    return 0;
}
