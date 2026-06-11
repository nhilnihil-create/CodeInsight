#include<bits/stdc++.h>
using namespace std;
 int main(){
int n;
cin >> n;
int t=n%10;
if(t==3)cout <<"bon";
else if(t==1||t==0||t==6||t==8)cout <<"pon";
else cout << "hon";
}
