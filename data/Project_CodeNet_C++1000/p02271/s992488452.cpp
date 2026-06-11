#include<cstdio>
#include<vector>

std::vector<int> A;

int solve(int depth,int m){
  if(m==0){return 1;}
  if(depth==A.size()){return 0;}
  
  return solve(depth+1,m)||solve(depth+1,m-A[depth]);
}

int main() {
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    int tmp;
    scanf("%d",&tmp);
    A.push_back(tmp);
  }
  
  int q;
  scanf("%d",&q);
  for(int i=0;i<q;++i){
    int tmp;
    scanf("%d",&tmp);
    printf("%s\n", solve(0,tmp)? "yes" : "no");
  }
  
  return 0;
}