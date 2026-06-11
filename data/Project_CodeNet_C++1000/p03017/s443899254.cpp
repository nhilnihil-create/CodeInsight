# include <iostream>
# include <string>
using namespace std;
int main(){
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  char grid[n+5];
  for(int i=1; i<=n; i++) cin >> grid[i];

  for(int i=a; i<c; i++){
    if(grid[i] == '#' && grid[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }

  for(int i=b; i<d; i++){
    if(grid[i] == '#' && grid[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }

  if(c < d){
    cout << "Yes" << endl;
  }
  else{
    for(int i=2; i<n; i++){
      if(grid[i-1] == '.' && grid[i] == '.' && grid[i+1] == '.' && b <= i && i <= d){
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
  return 0;
}
