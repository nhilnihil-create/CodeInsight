#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string n;
    cin>>n;
    long long g = 0;
    for(long i= 0;i<n.length();i++){
    	char c = n[i];
		int  f = c - '0';
        g += f;
    }
    if(g%9==0) cout<<"Yes";
    else cout<<"No";
    return 0;
}