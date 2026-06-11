# include <iostream>
using namespace std;

int ans[1005][1005];
int main(){
  int R, C, A, B;
  cin >> R >> C >> A >> B;
  for(int i=1; i<=B; i++){
    for(int j=A+1; j<=C; j++)
      ans[i][j] = 1;
  }

  for(int i=B+1; i<=R; i++){
    for(int j=1; j<=A; j++){
      ans[i][j] = 1;
    }
  }

  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}