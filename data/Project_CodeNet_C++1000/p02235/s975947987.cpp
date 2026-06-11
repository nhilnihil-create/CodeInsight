#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  
  int q, lcs[1010][1010] = {};
  string a, b;

  //input
  cin >> q;
  for(int i = 0;i < q;i++){
    cin >> a;
    cin >> b;

    for(int r = 0;r < (int)a.size();r++){
      for(int c = 0;c < (int)b.size();c++){
	//if a_i = b_j, chain a_i to LCS of a_{i-1} and b_{j-1}
        if(a[r] == b[c]) lcs[r + 1][c + 1] = lcs[r][c] + 1;
	//else LCS of a_{i-1} and b_j or a_i and b_{j-1}
        else lcs[r + 1][c + 1] = max(lcs[r + 1][c], lcs[r][c + 1]);
      }
    }
    
    //output
    cout << lcs[a.size()][b.size()] << endl;
  }
  
  return 0;
}


