#include <iostream>
#include <vector>
using namespace std;

long long int solutions;
bool grandFlag;

void print(vector<vector<int> >& pz){
  for(int i=0; i<pz.size(); i++){
    for(int j=0; j<5; j++)
      cout << pz[i][j] << " ";
    cout << endl;
  }
};

void solve(vector<vector<int> >& pz){
  for(int i=pz.size()-1; i>=0; i--){
    int a = pz[i][0], x = 1, pos = 0;
    bool yes = false;
    for(int j=1; j<5; j++){
      if(pz[i][j] == a && a!=0)
	x++;
      else if(x>=3) {
	yes = true;
	pos = j-1;
	break;
      }
      else{
	x = 1;
	a = pz[i][j];
      }
      if(j == 4 && x>=3){
	yes = true;
	pos = j;
      }
    }
    if(yes == 1){
      for(int j=pos; j>pos-x; j--)
	pz[i][j] = 0;
      solutions += (a*x);
      grandFlag = true;
    }
  }
};

void simplify(vector<vector<int> >& pz){
  int lowest; bool set;
  for(int j=0; j<5; j++){
    lowest = pz.size();
    set = false;
    for(int i=pz.size()-1; i>=0; i--){
      if(pz[i][j] == 0 && !set){
	lowest = i;
	set = true;
      }
      else if(pz[i][j] != 0 && set){
	swap(pz[i][j], pz[lowest][j]);
	lowest--;
      }
    }
  }
};

void slv(vector<vector<int> >& pz){
  while(grandFlag){
    grandFlag = false;
    solve(pz);
    simplify(pz);
  }
};

int main(){
  int h;
  cin >> h;
  while(h!=0){
    solutions = 0;
    grandFlag = true;
    vector<vector<int> > pz(h, vector<int>(5));
    for(int i=0; i<h; i++)
      for(int j=0; j<5; j++)
	cin >> pz[i][j];

    slv(pz);
    cout << solutions << endl;
    cin >> h;
  }

  return 0;
}