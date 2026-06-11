#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a[3]={};
  for(int i=0; i<2; i++){
    int b;
    cin >> b;
    b--;
    a[b]++;
  }
  for(int i=0; i<3; i++){
    if(a[i]==0) cout << i+1 << endl;
  }
  return 0;
}
