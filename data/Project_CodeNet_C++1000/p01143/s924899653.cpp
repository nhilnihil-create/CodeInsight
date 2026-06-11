#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char judge(int a[],int m1)
{
   int i,j,k,l;
   int x[100];
   int n; /* 投票の対象となる競技者の数 */
   int m; /* 優勝した競技者の番号 */
   int p; /* 控除率（百分率）を表す整数 */
   int sum = 0; /* 人数の合計 */
   cin >> n >> m >> p;
   if(n == 0 && m == 0 && p == 0) return 0;

   for(i=0;i<n;i++) {
      cin >> x[i];
      sum += x[i];
   }
   if(x[m-1])
      a[m1] = sum * (100-p) / x[m-1] ;
   else a[m1] = 0;
   return 1;
}



int main()
{
   int i,j,k,l;
   int m1;
   int a[100];
   int go = 1;
   for(i=0;go;i++) {
      go = judge(a,i);
   }
   i--;
   m1 = i;
   for(i=0;i<m1;i++)
      cout << a[i] << endl;
   return 0;
}