# include <iostream>
# include <vector>
# include <set>
using namespace std;

bool allZero(vector<int> num){
  for(int x : num){
    if(x != 0) return false;
  }
  return true;
}

int getOtherZero(vector<int> num){
  for(int x : num){
    if(x != 0) return x;
  }
  return -1;
}

bool typeOne(vector<int> num){
  int otherZero = getOtherZero(num);
  int cntZero = 0;
  int cntOther = 0;
  for(int x : num){
    if(x==0) cntZero++;
    else if(otherZero == x) cntOther++;
  }

  if(cntZero == num.size()/3 && cntOther == num.size()*2/3) return true;
  return false;
}

bool typeTwo(vector<int> num){

  vector<int> original = num;
  set<int> temp;
  for(int x : num) temp.insert(x);
  if(temp.size() != 3) return false;

  num.clear();
  for(int x : temp) num.push_back(x);

  int a = num[0], b = num[1], c = num[2];
  if((a^b^c) != 0) return false;

  int cntA = 0, cntB = 0, cntC = 0;
  for(int x : original){
    if(x == a) cntA++;
    else if(x == b) cntB++;
    else if(x == c) cntC++;
  }

  return (cntA == original.size()/3 && cntB == original.size()/3 && cntC == original.size()/3);
}

string solve(vector<int> num){
  if(allZero(num)) return "Yes";
  if(num.size()%3 != 0) return "No";
  if(typeOne(num) || typeTwo(num)) return "Yes";
  return "No";
}

int main(){
  int n;
  cin >> n;

  vector<int> num(n);
  for(int i=0; i<n; i++) cin >> num[i];
  cout << solve(num) << endl;
  return 0;
}