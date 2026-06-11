#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
 
int main() {
	int n, inpnum;
	scanf("%d", &n);
	char comm[20];

	list<int> linkedlist;
	for(int comind = 0; comind < n; comind++){
		scanf("%s", comm);

		if(comm[0] == 'i'){
			scanf("%d", &inpnum);
			linkedlist.push_front(inpnum);
		}else if(comm[6] == 'L'){
			linkedlist.pop_back();
		}else if(comm[6] == 'F'){
			linkedlist.pop_front();
		}else{
			scanf("%d", &inpnum);
			for(list<int>::iterator it = linkedlist.begin(); it != linkedlist.end(); it++){
				if(*it == inpnum){
					linkedlist.erase(it);
					break;
				}
			}
		}
	}

	int allsize = linkedlist.size();
	for(int i = 0; i < allsize;){
		if(i++){
			printf(" ");
		}
		printf("%d", linkedlist.front());
		linkedlist.pop_front();
	}

	printf("\n");
}