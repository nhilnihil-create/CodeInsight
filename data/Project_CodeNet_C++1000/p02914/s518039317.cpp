#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N;
  std::cin>>N;
  std::vector<long long> A(N);
  int cnt[60];
  long long ans=0;
  for (int i=0;i<60;++i) cnt[i]=0;
  for (int i=0;i<N;++i) {
    std::cin>>A[i];
  }
  for (int shift=0;shift<60;++shift) {
    for (int i=0;i<N;++i) {
      if ((A[i]&(1LL<<shift))>0) ++cnt[shift];
    }
    if (cnt[shift]%2==1) {
      ans+=1LL<<shift;
      for (int i=0;i<N;++i) if ((A[i]&(1LL<<shift))>0) A[i]-=1LL<<shift;
      cnt[shift]=0;
    }
  }
  std::sort(A.begin(), A.end());
  int p=0;
  for (int shift=59;shift>=0;--shift) {
    if (cnt[shift]==0) continue;
    for (int i=p;i<N;++i) {
      if (((1L<<shift)&A[i])>0) {
	if (i!=p) {
	  A[i]^=A[p];
	  A[p]^=A[i];
	  A[i]^=A[p];
	}
	for (int j=0;j<N;++j) {
	  if (j==p) continue;
	  if ((A[j]&(1LL<<shift))>0) A[j]^=A[p];
	}
	++p;
	break;
      }
    }
  }
  long long a=0;
  for (int i=0;i<N;++i) {
    a^=A[i];
  }
  ans+=2*a;
  std::cout<<ans<<std::endl;
}
