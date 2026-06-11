#include <bits/stdc++.h>

using namespace std;

int main()
{
	int V, E;

	scanf("%d %d", &V, &E);

	int *box, *pos;
	box = (int*)malloc(sizeof(int) * V);
	pos = (int*)malloc(sizeof(int) * V);
	for(int i = 0; i < V; i++){
		box[i] = i;
		pos[i] = i;
	}

	int from, to;
	for(int i = 0; i < E; i++){
		scanf("%d %d", &from, &to);

		int k = pos[to];
		while(pos[to] < pos[from]){
			int tmp = box[k];
			int tmp2 = pos[box[k]];

			pos[box[k]] = pos[box[k + 1]];
			box[k] = box[k + 1];

			pos[box[k + 1]] = tmp2;
			box[k + 1] = tmp;
			k++;
		}
	}

	for(int i = 0; i < V; i++){
		if(i)
			printf(" ");
		printf("%d", box[i]);
	}

	return 0;
}
