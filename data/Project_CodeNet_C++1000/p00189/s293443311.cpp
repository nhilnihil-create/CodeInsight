#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int INF = 100000000;


int d[10][10];
int ans1, ans2;
bool town[10];


main(){
   int n;
   while(cin >> n && n){
      fill(d[0], d[10], INF);
      fill(town, town+10, false);
      for(int i=0;i<n;i++){
         int a, b, c;
         cin >> a >> b >> c;
         town[a] = true;
         town[b] = true;
         d[a][b] = d[b][a] = c;
      }
      for(int k=0;k<10;k++){
         for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
               d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
         }
      }
      ans2 = INF;
      for(int i=0;i<10;i++){
         if(!town[i]) continue;
         int sum = 0;
         for(int j=0;j<10;j++){
            if(i == j) continue;
            if(!town[j]) continue;
            sum += d[i][j];
         }
         if(ans2 > sum){
            ans2 = sum;
            ans1 = i;
         }
      }
      cout << ans1 << ' ' << ans2 << endl;
   }
   return 0;
}