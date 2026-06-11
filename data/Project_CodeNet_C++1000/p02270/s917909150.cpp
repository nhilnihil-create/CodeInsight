#include<iostream>
#include<climits>
int check(int*,int);
int n, k;
int main(){
  std::cin >> n >> k;
  int W[n];
  for(int i=0; i<n; i++) std::cin >> W[i];
  int l=0, r=INT_MAX, m;     // solve
  while(r-l>1){              // *
    m = (r + l) / 2;         // *
    int v = check(W, m);     // *
    v >= n ? r = m : l = m;  // *
  }                          // end
  std::cout << r << std::endl;
  return 0;
}
int check(int *W,int p){
  int i=0;
  for(int j=0; j<k; j++){
    int s=0;
    while(s+W[i] <= p){
      s += W[i];
      i++;
      if(i == n) return n;
    }
  }
  return i;
}