#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  int array[n];
  REP(i,n) array[i] = i+1;
  vector<int> array1(n);
  vector<int> array2(n);
  
  REP(i,n){
    cin >> array1[i];
  }
  REP(i,n){
    cin  >> array2[i];
  }
  
  int a = 0,b = 0,c = 1;
  do{
    bool can1 = true;
    bool can2 = true;
    /*for(int i=0; i<n; i++){
      cout<<array[i];
      if(i!=n-1)cout<<" ";
    }
    cout << endl;*/
    
    REP(i,n){
      if(array[i] != array1[i]){
        can1 = false;
      }
      if(array[i] != array2[i]){
        can2 = false;
      }
    }
    
    if(can1){
      a = c;
    }
    if(can2){
      b = c;
    }
    //if(can2) b = c;
   /* bool can1 = true;
    bool can2 = true;
    REP(i,n){
      if(array[i] != array1[i]){
        can1 = false;
      }
      if(array[i] != array2[i]){
        can2 = false;
      }
      if(can1) a = c;
      if(can2) b = c;
    }*/
    c++;
    can1 = true;
    can2 = true;
  }while(next_permutation(array,array+n));  
  
  cout << abs(a-b) << endl;
  

  
}