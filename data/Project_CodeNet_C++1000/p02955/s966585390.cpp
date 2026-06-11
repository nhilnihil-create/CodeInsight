#include <bits/stdc++.h>
using namespace std;
 
int main() {
int a;
  cin >> a;
  int k;
  cin >> k;
  vector<int> z(a);
  int d=0;
  for(int i = 0;i<a;i++){
    cin >> z.at(i);
    d+=z.at(i);
  }
  
  vector<int> s;
  for(int i = 1;i<=sqrt(d);i++){
    if(d%i==0){s.push_back(i);
               s.push_back(d/i);}
  }
  sort(s.begin(),s.end());

    int t = 1;
  for(int i = 0;i<s.size();i++){
    int p=0;
    vector<int> x(a);
    for(int j = 0;j<a;j++){
      p+=z.at(j)%s.at(i);
    x.at(j)=z.at(j)%s.at(i);}
    
    sort(x.begin(),x.end());
    reverse(x.begin(),x.end());
    int y = p;
    p/=s.at(i);
    for(int j = 0;j<p;j++){
      y -= x.at(j);}
    if(y<=k)t=s.at(i);
  }
    cout << t << endl;
}