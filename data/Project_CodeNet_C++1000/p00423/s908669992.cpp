#include<iostream>
#include<vector>

using namespace std;
int main(void){
  int n,j = 0,i,c,a[10000],b[10000];
  /* vector <int> a;
     vector <int> b;*/
  vector <int> d;
  vector <int> sa(10000,0);
  vector <int> sb(10000,0);
  while(cin >> n,n != 0){
    for(i=0;i<n;i++){
      cin >> a[i];
      cin >> b[i];
    }
    
    i=0;
    for(i=0;i<n;i++){
      c = a[i] + b[i];
      if(a[i] > b[i]) sa[j] = sa[j] + c;
      else if(a[i] < b[i]) sb[j] = sb[j] + c;
      else{
	sa[j] = sa[j] + c/2;
	sb[j] = sb[j] + c/2;
      }
    }
    j++;

    cout << sa[j-1] << " " << sb[j-1] << endl;
  }
}