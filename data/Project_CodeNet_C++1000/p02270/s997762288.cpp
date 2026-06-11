#include <iostream>
#include <algorithm>
using namespace std;

bool bsearch(const int array[], int left, int right, int value){
  while (left + 1 < right){
    int med = (left+right)/2;
    if (array[med] > value) right = med;
    else left = med;
  }
  return left < right && array[left] == value;
}

bool ok(int P,int n,int k,int w[]){
  int max=0,count=1,weight=P;
  
  for (int i=0;i<n;i++){
    if (w[i]>max) max=w[i];
    
    if (w[i]>weight){
      count ++;
      weight = P - w[i];
    }else{
      weight = weight - w[i];
    }
  }
    return k >= count && P >= max;
}

int main(){
  int n,k,w[100100];
  cin >> n >> k;
  
  for (int i=0;i<n;i++){
    cin >> w[i];
  }

  int l=0, h=1000000050;
  while (l+1<h){
    int m=(l+h)/2;
    if(ok(m,n,k,w)) h=m ; else l=m;
  }
  cout << h << endl;  
  return 0;
}