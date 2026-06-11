#include<cstdio>
#include<vector>
#include<map>
#include<string>

using namespace std;

int n;
char s[105];
vector<pair<string, int> > songs;

int main(){
	//freopen("IN","r",stdin);

	scanf("%d",&n);
	for(int i = 0; i < n;i++){
		int m;
		scanf("%s%d",s,&m);
		string name = s;
		songs.push_back({name,m});
	}
	scanf("%s",s);
	string name = s;
	int i = 0;
	for(;i < n;i++){
		if(songs[i].first == name) break;
	}
	i++;
	int res = 0;
	for(;i < n;i++){
		res += songs[i].second;
	}
	printf("%d\n", res);
}