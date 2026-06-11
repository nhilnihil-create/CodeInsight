#include <bits/stdc++.h>
using namespace std;
int main(void){
   int x,y,cnt = 0;;
   cin >> x >> y;
   if(1<=x&&x<=3) cnt += (4-x)*100000;
   if(1<=y&&y<=3) cnt += (4-y)*100000;
   if(x==y&&x==1) cnt += 400000;
   cout << cnt << endl;
}