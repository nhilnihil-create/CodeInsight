#include<bits/stdc++.h>
using namespace std;
int main(){
 int n; cin >> n;

 set <string>s;
 for(int i=0;i<n;i++){
     string t;
     cin >> t;
     s.insert(t);
 }

 int b=s.size();
cout << b << endl;

}
