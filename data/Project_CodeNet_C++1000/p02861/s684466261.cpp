#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
#include<vector>
#include<math.h>
using namespace std;

const int BIG=100000000;

int main(){
  int N;
  cin>>N;
  int A[N][2];
  for(int i=0;i<N;i++){
    cin>>A[i][0]>>A[i][1];
  }
  vector<int> order(N);
  for(int i=0;i<N;i++) order[i]=i;
  double lensum=0;
  do{
    for(int i=0;i<N-1;i++){
     lensum += sqrt(pow((A[order[i]][0]-A[order[i+1]][0]),2)+pow((A[order[i]][1]-A[order[i+1]][1]),2));
    }
  }while(next_permutation(order.begin(), order.end()));
   
   double mother=1;
   for(int i=N;i>=1;i--) mother *=i;                                                             
    printf("%f7",lensum/mother);                                                                        
                                                                            
}