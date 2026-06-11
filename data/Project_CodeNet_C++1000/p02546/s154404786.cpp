#include<bits/stdc++.h>
using namespace std;

#define ll long long int

static const auto _____ = []() {
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(0);
    return 0;
}();

int main(){
	string s;
	cin>>s;
	if(s[(s.size()-1)] == 's')
		s.append("es");
	else
		s.append("s");
	cout<<s<<endl;
	return 0;
}
