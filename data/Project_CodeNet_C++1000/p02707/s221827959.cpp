#include <iostream>
#include <map>
using namespace std;
int main() {
    int n,q;
    cin>>n;
    q=n;
    int t;
    map<int,int> dd;
    n--;
    while(n--){
    	cin>>t;
    	dd[t]++;
    }
    for(int i=1;i<=q;i++){
    	cout<<dd[i]<<endl;
    }
    return 0;
}
