#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int>graph[100001];
bool visit[100001];
int d[100001];
int n;
int tim;

void dfs(int now,int t){
  visit[now] = false;
  
  d[now] = t;
  for (int i = 0; i < graph[now].size() ; ++i) {
    if ( visit[graph[now][i]] ){
      dfs(graph[now][i],t);
    }
  }

  return;
}

main()
{
  int m, q;
  int s, t;
  
  scanf("%d %d", &n, &m);
  for ( int i = n; i < n*2 ; ++i) {
    d[i - n] = i;
    visit[i-n] = true;
  }

  for ( int i = 0; i < m ; ++i) {
    scanf("%d %d", &s, &t);
    graph[s].push_back(t);
    graph[t].push_back(s);
  }

  for ( int i = 0; i < n ; ++i) {
    if ( visit[i] ) {
      dfs(i,tim);
      tim++;
    }
  }
  
  scanf("%d", &q);
  for ( int i = 0; i < q ; ++i) {
    scanf("%d %d", &s, &t);
    if ( d[s] == d[t] ) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return (0);
}

