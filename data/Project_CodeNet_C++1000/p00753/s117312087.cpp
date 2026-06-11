#include <bits/stdc++.h>
using namespace std;
/*cout <<"Debug"
cout <<x-30<<' '<<y-30<<endl;*/
vector<string>v;
vector<int>ansl;
string s;
int ary[100005] = {0};
int mp[200][200];
int cnt = 0;
int d_x[] = {1, 1, 0, -1, -1, 0};
int d_y[] = {1, 0, -1, -1, 0, 1};
int t;
/*
void dfs(int x,int y,int lpcnt){
  mp[x][y] = 1;
  cout <<"Debug ";
  cout <<x-30<<' '<<y-30<<endl;
  cnt++;
  lpcnt++;
  int watasi = lpcnt;
  int used[6] = {0};
  for(int dx = 0;dx<6;dx++){
    int nx = x+d_x[dx],ny = y+d_y[dx];
    int dft = sqrt((nx-30)*(nx-30)+(ny-30)*(ny-30));
    if((dft<=30)&&(watasi < t)&&(mp[nx][ny] == 0)){
        dfs(nx,ny,watasi);
        used[dx] = 1;
    }
    for(int i = 0;i<6;i++){
      if(used[i]){
        if((nx == x + d_x[i])&&(ny == y + d_y[i])){
          dfs(nx,ny,watasi);
        }
      }
    }
    }
}
*/
int main(){
  long int N;

  cin >>N;
  while(N != 0){
    int cnt = 0;

    for(long int i = N+1;i<=2*N;i++){
      long int x = i,waru = sqrt(i),flg = 0;
      if(i == 2){
        cnt++;
        break;
      }
      if(i%2 == 0){
        continue;
      }
      while (waru > 1) {
        if(x%waru == 0){
          flg = 1;
          break;
        }
        waru--;
      }
      if(flg == 0)cnt++;
    }
    ansl.push_back(cnt);
    cin >>N;
  }

  for(int i = 0;i<(int)ansl.size();i++){
    cout <<ansl[i]<<endl;
  }
  return 0;
}

