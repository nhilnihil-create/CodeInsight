//#define DEBUG
using namespace std;

bool prime[1000000] = {0};
int a, d, n;

int main(){
	for(int i = 2; i < 1000; i++){
		if(!prime[i]){
			for(int j = i*2; j < 1000000; j+=i){
				prime[j] = true;
			}
		}
	}
	prime[0] = prime [1] = 1;
	#ifdef DEBUG_prime
	for(int i = 2; i < 100; i++)if(!prime[i])cout<<i<<endl;
	#endif
	while(cin>>a>>d>>n, a||d||n){
		int i, c = 0;
		for(i = a; i < 1000000; i += d){
			if(!prime[i]){
				c++;
				if(c == n)break;
			}
		}
		cout<<i<<endl;
	}
	return 0;
}