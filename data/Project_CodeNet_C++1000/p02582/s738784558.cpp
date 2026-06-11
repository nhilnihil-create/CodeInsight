#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string a;
    cin>>a;
    if(a[0] =='R'&&a[0] == a[1] &&a[1] == a[2]){cout<<3;}
	else if(a[0]== 'R'&&a[1] == 'R'||a[1]== 'R'&&a[2] == 'R'){cout<<2;}
    else if(a[0] =='S'&&a[0] == a[1] &&a[1] == a[2]){cout<<0;}
    else{cout<<1;}
    return 0;
}