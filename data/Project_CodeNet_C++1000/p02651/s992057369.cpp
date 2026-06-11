#include <cstdio>
#include <vector>

int main()
{
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d",&n);
    std::vector<long long> a(n);
    for(int i=0;i<n;i++){
      scanf("%lld",&a[i]);
    }
    char s[300];
    scanf("%s",s);
    std::vector<long long> bs(64);
    std::vector<int> tp(64);
    int dim=0;
    bool ans=true;
    for(int i=n-1;i>=0;i--){
      long long v=a[i];
      int t=0;
      while(t<dim){
	if((v&((1ll<<tp[t])-1))!=0){
	  break;
	}
	//printf(" %lld %d %d %lld\n",v,t,tp[t],bs[t]);
	if(v&(1ll<<tp[t])){
	  v^=bs[t];
	}
	t++;
      }
      //printf("%d %lld %d %d\n",i,v,dim,t);
      if(v!=0){
	if(s[i]=='0'){
	  for(int x=dim;x>t;x--){
	    bs[x]=bs[x-1];
	    tp[x]=tp[x-1];
	  }
	  bs[t]=v;
	  tp[t]=0;
	  while((v&(1ll<<tp[t]))==0){
	    tp[t]++;
	  }
	  dim++;
	}
	else{
	  ans=false;
	  break;
	}
      }
    }
    puts(ans?"0":"1");
  }
  return 0;
}
