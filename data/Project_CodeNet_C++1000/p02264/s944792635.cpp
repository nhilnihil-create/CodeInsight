#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char name[15];
  int time;

} process;

int main(void){
  int n;
  int q;
  int i, j, k;
  int p_time = 0;
  process *processes;
  int head = 0;
  int tail = 0;
  int size;

  scanf("%d%d", &n, &q);
  size = n + 2;
  processes = (process *)malloc(sizeof(process) * size);
  tail = n;

  for(i = 0; i < n; i++){
    scanf("%s", processes[i].name);
    scanf("%d", &processes[i].time);
  }

  while(head != tail){
    if(processes[head].time <= q){
      p_time += processes[head].time;
      printf("%s %d\n", processes[head].name, p_time);
      head = (head + 1) % size;
    }else {
      p_time += q;
      processes[head].time -= q;
      processes[tail] = processes[head];
      tail = (tail + 1) % size;
      head = (head + 1) % size;
    }
  }

  free(processes);
  return 0;
}