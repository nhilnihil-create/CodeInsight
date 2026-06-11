#include <bits/stdc++.h>
using namespace std;

#define print cout <<

class StrProc{
  public :
    string removeTargetStr(string rowStr, string target){
      int start_idx = rowStr.find(target);
      while(start_idx!=string::npos){
        rowStr.replace(start_idx,target.size(),"");
        start_idx = rowStr.find(target);
      }
      return rowStr;
    }

    vector<int> calculateSimiralities(string rowStr, string target){
      int idx_size = rowStr.size() - target.size() + 1;
      vector<int> results(idx_size);
      for(int i=0;i<idx_size;i++){
        string cropped = rowStr.substr(i,target.size());
        results.at(i) = calculateSimirality(cropped,target);
      }
      return results;
    }

    int calculateSimirality(string rowStr, string target){
      int same = 0;
      for(int i=0;i<rowStr.size();i++){
        if(rowStr.at(i)==target.at(i)){
          same +=1;
        }
      }
      return same;
    } 
};

int main(){
    string S,T;
    cin >> S >> T;
    auto pro = StrProc();
    auto sim = pro.calculateSimiralities(S, T);

    int max = *max_element(sim.begin(), sim.end());
    int sub = T.size() - max;
    print sub << endl;
}
