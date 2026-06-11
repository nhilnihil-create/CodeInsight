#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int j=1;
    for(auto x:s)
    {
        if(j<=3)
        cout<<x;
        else break;
        j++;
    }
	return 0;
}