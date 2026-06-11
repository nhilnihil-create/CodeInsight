#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
  	cin >> n;
  	vector<int> s(n);
  	int d = 0, e = 0;
  	for(int i=0;i<n;i++){
      cin >> s.at(i);
    if(s.at(i)%2==0) d++;
    if(s.at(i) % 2 == 0 && (s.at(i) % 3 == 0 || s.at(i) % 5 == 0)) e++;
    }
  	if(e != d) cout <<"DENIED"<<endl;
  	else cout << "APPROVED" << endl;
}