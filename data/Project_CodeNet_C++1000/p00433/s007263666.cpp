using namespace std;
int p[7];
int main(){
	for(int i=0;i<8;i++)cin>>p[i],p[i]+=(i>1&&i%4?p[i-1]:0);
	cout<<(p[3]>p[7]?p[3]:p[7])<<endl;
	return 0;
}