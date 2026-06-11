#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
    int ans = 0;
    for(int i=n;i>0;--i){
        string tmp = to_string(i);
        if(tmp.size()%2==1)++ans;
    }
    cout<<ans<<endl;
	return 0;
}