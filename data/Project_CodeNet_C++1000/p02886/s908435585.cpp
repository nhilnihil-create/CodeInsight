#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int d[101];
    for(int i = 0; i < n; i++)
        scanf("%d", &d[i]);

   long sum = 0;

   for(int i = 0 ; i < n - 1; i++){
      for(int j = i + 1 ; j < n ; j++){
        sum = sum + (d[i] * d[j]);
      }
   }
   printf("%ld\n", sum);
   return 0;
}
