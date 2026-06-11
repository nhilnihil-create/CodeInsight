#include <iostream>
#include <vector>

int main(){
   int N;
   std::string S;
   std::cin >> N >> S;

   std::vector<int> R, G, B;
   for(int i=0; i<N; ++i){
      if(S[i]=='R') R.push_back(i);
      else if(S[i]=='G') G.push_back(i);
      else if(S[i]=='B') B.push_back(i);
   }
   const int NR = R.size();
   const int NG = G.size();
   const int NB = B.size();
   int r(0), g(0), b(0);
   long long ans = 0;
   for(int i=0; i<N; ++i){
      if(S[i]=='R'){
	 for(int j=g; j<NG; ++j){
	    ans += NB - b;
	    int k = G[j] - i + G[j];//R, G, B
	    if(k<N && S[k]=='B') --ans;
	    k = (G[j] - i)%2==0 ? (G[j] - i)/2 + i : N;//R, B, G
	    if(k<N && S[k]=='B') --ans;
	 }
	 ++r;	
      }else if(S[i]=='G'){
	 for(int j=b; j<NB; ++j){
	    ans += NR - r;
	    int k = B[j] - i + B[j];//G, B, R
	    if(k<N && S[k]=='R') --ans;
	    k = (B[j] - i)%2==0 ? (B[j] - i)/2 + i : N;//G, R, B
	    if(k<N && S[k]=='R') --ans;
	 }
	 ++g;	
      }else if(S[i]=='B'){
	 for(int j=r; j<NR; ++j){
	    ans += NG - g;
	    int k = R[j] - i + R[j];//B, G, R
	    if(k<N && S[k]=='G') --ans;
	    k = (R[j] - i)%2==0 ? (R[j] - i)/2 + i : N;//B, R, G
	    if(k<N && S[k]=='G') --ans;
	 }
	 ++b;	
      }
   }

   std::cout << ans << std::endl;
   return 0;
}
