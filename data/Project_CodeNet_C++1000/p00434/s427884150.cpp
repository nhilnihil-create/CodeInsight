using namespace std;
int f[31];
int main(){
	int n;
	while(cin>>n)f[n]=1;
	for(int i=1;i<31;i++)if(!f[i])cout<<i<<endl;
	return 0;
}